#include<bits/stdc++.h>
using namespace std;
int xxxx,n,m,p,o,cnt,num[59],a[1009][1009],in[1009][1009],d[59],b[45][1009][1009],f[45][1009][1009],xx,yy,q,x1,yy1,x2,yy2,ans,aans,res;
int main(){
//	freopen("tsuki.in","r",stdin);
//	freopen("tsuki.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	o=p;
	cnt=0;
	xxxx=p;
	for(int i=2;i*i<=o&&o>1;i++){
		if(o%i==0){
			cnt++;
			d[cnt]=i;
			o/=i;
			num[cnt]=i;
			xxxx/=i;
			xxxx*=i-1;
		}
		while(o%i==0){
			o/=i;
			num[cnt]++;
		}
	}
	xxxx/=o;
	xxxx*=o-1;
	cnt++;
	d[cnt]=o;
	num[cnt]++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			o=a[i][j];
			for(int k=1;k<=cnt;k++){
				while(o%d[k]==0){
					o/=d[k];
					b[k][i][j]++;
				}
			}
			a[i][j]=o;
		}
	}
	for(int i=1;i<=m;i++)f[0][0][i]=in[0][i]=1;
	for(int i=0;i<=n;i++)f[0][i][0]=in[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[0][i][j]=1ll*f[0][i][j-1]*f[0][i-1][j]%p*a[i][j]%p*in[i-1][j-1]%p;
			for(int k=1;k<=cnt;k++){
				f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1]+b[k][i][j];
			}
			xx=xxxx-1;
			in[i][j]=1;
			yy=f[0][i][j];
			while(xx){
				if(xx&1)in[i][j]=1ll*in[i][j]*yy%p;
				xx>>=1;
				yy=1ll*yy*yy%p;
			}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&x1,&yy1,&x2,&yy2);
		ans=1ll*f[0][x2][yy2]*f[0][x1-1][yy1-1]%p*in[x2][yy1-1]%p*in[x1-1][yy2]%p;
		for(int i=1;i<=cnt;i++){
			aans=f[i][x2][yy2]+f[i][x1-1][yy1-1]-f[i][x2][yy1-1]-f[i][x1-1][yy2];
			for(int j=min(aans,num[i]);j;j--){
				ans=1ll*ans*d[i]%p;
			}
		}
		res=(res+(ans^i))%147744151;
	}
	printf("%d\n",res);
	return 0;
}
