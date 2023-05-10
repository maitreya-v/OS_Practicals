#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, m;
    // n is the number of processes
    // m is the number of resources
    printf("Enter the number of rows ");
    scanf("%d", &n);
    printf("Enter the number of column ");
    scanf("%d", &m);

    int alloc[n][m];
    int max[n][m];
    int avail[m];

    int need[n][m];
    int f[n], ans[n], ind = 0;

    printf("Allocation array\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Row %d, column %d ", i, j);
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Max array\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Row %d, column %d ", i, j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Available array\n");

    for (int i = 0; i < m; i++)
    {
        printf("Column %d ", i);
        scanf("%d", &avail[i]);
    }

    printf("Calculating Need\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        f[i]=0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;

                for(int j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    f[i]=1;
                    ans[ind++]=i;

                    for(int x=0;x<m;x++){
                        avail[x]+=alloc[i][x];
                    }
                }
            }
        }
    }

    int flag=1;

    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("Unsafe");
            break;
        }
    }

    if(flag==1){
        printf("The sequence is ");
        for(int i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
    }

    return 0;
}