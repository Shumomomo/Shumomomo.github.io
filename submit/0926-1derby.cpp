#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,l,r,cnt1,cnt2,cnt3,cnt4,s1[100009],s2[100009],s3[100009],s4[100009],ans;
int main(){
	freopen("derby3.in","r",stdin);
	freopen("derby.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a,&b);
		if(a){
			cnt1++;
			s1[cnt1]=b;
		}
		else{
			cnt2++;
			s2[cnt2]=b;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&a,&b);
		if(a){
			cnt3++;
			s3[cnt3]=b;
		}
		else{
			cnt4++;
			s4[cnt4]=b;
		}
	}
	sort(s1+1,s1+cnt1+1);
	sort(s2+1,s2+cnt2+1);
	sort(s3+1,s3+cnt3+1);
	sort(s4+1,s4+cnt4+1);
	ans=0;
	l=cnt1;
	r=cnt4;
	while(r&&l){
		while(r>1&&s4[r]>=s1[l])r--;
		if(s4[r]<s1[l])ans+=s4[r]+s1[l];
		l--;
		r--;
	}
	l=cnt3;
	r=cnt2;
	while(r&&l){
		while(r>1&&s2[r]>=s3[l])r--;
		if(s2[r]<s3[l])ans+=s2[r]+s3[l];
		l--;
		r--;
	}
	printf("%lld\n",ans);
	return 0;
} 
