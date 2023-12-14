#include<bits/stdc++.h>
using namespace std;
long long n,K,f[3][100][4009],ans,no;
int main(){
	scanf("%lld%lld",&n,&K);
	no=1;
	f[no][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			no^=1;
			for(int k=0;k<(1<<(n+1));k++){
				for(int l=0;l<=K;l++){
					f[no][l][k]=0;
				}
			}
			for(int k=0;k<(1<<(n+1));k++){
				int q=k;
				q|=k<<1;
				q|=k>>1;
				q|=k>>2;
				q>>=j;
				q&=1;
				if(!q){
					for(int l=1;l<=K;l++){
						f[no][l][k|(1<<j)]+=f[no^1][l-1][k];
					}
				}
				int p=(1<<(n+1));
				p--;
				p^=(1<<j);
				for(int l=0;l<=K;l++){
					f[no][l][k&p]+=f[no^1][l][k];
				}
			}
			if(j==n-1){
				for(int l=0;l<=K;l++){
					for(int k=0;k<(1<<(n+1));k++){
						f[no^1][l][k]=0;
					}
					for(int k=0;k<(1<<(n+1));k++){
						f[no^1][l][(k<<1)&((1<<(n+1))-1)]+=f[no][l][k];
					}
				}
				no^=1;
			}
		}
	}
	for(int i=0;i<(1<<(n+1));i++)ans+=f[no][K][i];
	printf("%lld\n",ans);
	return 0;
}
//P1896
