#include <stdio.h>
#include <stdlib.h>
#define M 100001

int main() {
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    int**V=(int**)malloc(sizeof(int*)*(n+1));
    for(i=1; i<=n; i++) {
        V[i]=(int*)malloc(sizeof(int)*(n+1));
        for(j=1; j<=n; j++) {
            if(i==j)
			V[i][j]=0;
			else
            V[i][j]=M;
        }
    }
    while(m--) {
        int a,b;
        scanf("%d %d",&a,&b);
        V[a][b]=1;
        V[b][a]=1;
    }

    for(k=1; k<=n; k++) {
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(V[i][j]>V[i][k]+V[k][j])
                    V[i][j]=V[i][k]+V[k][j];
            }
        }
    }

    scanf("%d",&m);
    for(k=0; k<m; k++) {

        int a;
        scanf("%d",&a);

        printf("Cc(%d)=",a);
        int sum=0;
        for(i=1; i<=n; i++) 
		{
            if(V[a][i]==M) 
			{
                sum=0;
                break;
            } 
			else 
			sum+=V[a][i];
        }
        if(sum!=0)
            printf("%.2lf\n",(n-1)*1.0/sum);
        else 
		printf("0.00\n");

    }

    return 0;
}
