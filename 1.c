#include<stdio.h>
typedef struct Line line;
struct Line
{
	int point_1;
	int point_2;
};
void countingsort(int a[],int a1[],int n){
	int b[n],b1[n];
	int max=a[0], min=a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i]>max){max=a[i];}
		else if(a[i]<min){min=a[i];}
	}
	int k=max-min+1;
	int count[k];
	for (int i = 0; i < k; ++i)
	{
		count[i]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		count[a[i]-min]++;
	}
	for (int i = 1; i < k; ++i)
	{
		count[i]+=count[i-1];
	}
	for (int i = 0; i < n; ++i)
	{
		b[count[a[i]-min]-1]=a[i];
		b1[count[a[i]-min]-1]=a1[i];
		count[a[i]-min]--;
	}
	for (int i = 0; i < n; ++i)
	{   
	    a1[i]=b1[i];
		a[i]=b[i];
	}
}
int main(int argc, char **argv)
{
	int n, m;
	int i, j, k;
	printf("Versin:");
	scanf("%d", &n);
	printf("Reber:");
	scanf("%d", &m);
	line L[m];
	int result[n + 1][n + 1];
	for(i = 0; i < m; i++)
	{
		printf("point_1(%d):", i + 1);
		scanf("%d", &L[i].point_1);
		printf("point_2(%d):", i + 1);
		scanf("%d", &L[i].point_2);
	}
	for(i = 0; i < n + 1; i++)
	{
		result[0][i] = i;
		result[i][0] = i;
	}
	for(i = 1; i < n + 1; i++)
	{	
		for(j = 1; j < n + 1; j++)
		{
			result[i][j] = 0;
		}
	}
	
	for(i = 0; i < m; i++)
	{
		result[L[i].point_1][L[i].point_2] = 1;
		result[L[i].point_2][L[i].point_1] = 1;
	}
	for(i = 0; i < n + 1; i++)
	{
		printf("\n");
		for(j = 0; j < n + 1; j++)
		{
			printf("%d ", result[i][j]);
		}
	}
	printf("\n");
    int degree = 0;
    int degrees[n];
    int numbers[n];
    for (int i = 1; i <= n; i++)
    {
       for (int j = 1; j <= n; j++)
       {
           if (result[i][j]==1)
           { 
              degree++;
           }
		
       }
	    degrees[i-1] = degree;
        numbers[i-1] = i;
		degree = 0;
       
    }
    printf("All vertices with odd degrees:\n");
	countingsort(degrees,numbers,n);
	for (int i = n-1; i >=0 ; i--)
    {
        if ( degrees[i]%2==1)
        {
            printf("vertice %d : degree %d\n", numbers[i],degrees[i]);
        }  
    }
	FILE *f;
	f = fopen("graph.dot", "w");
	fprintf(f, "graph phong {\n");
	for(i = 0; i < m; i++)
	{
		fprintf(f, "%d--%d\n", L[i].point_1, L[i].point_2);
	}
	fprintf(f, "}");
	fclose(f);
	return 0;
}
