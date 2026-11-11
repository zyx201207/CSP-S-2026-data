#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans1,ans2,an1,an2,ans[N],g;
bool op=false;
signed main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=5 and m<=2)op=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(op){
		for(int i=1;i<=n;i++){
			int w1=0,w2=0;
			an1=0,an2=0;
			for(int j=i;j<=n;j++){
				if(w1 and a[j]==1){
					for(int k=w1;k<j;k++)an1-=(a[k]==1),an2-=(a[k]==2);
					if(an2<=0)w2=0;
					w1=j;
				}
				if(w2 and a[j]==2){
					for(int k=w2;k<j;k++)an1-=(a[k]==1),an2-=(a[k]==2);
					if(an1<=0)w1=0;
					w2=j;
				}
				if(w1==0 and a[j]==1)w1=j;if(w2==0 and a[j]==2)w2=j;
				an1+=(a[j]==1),an2+=(a[j]==2);
			}
			cout<<an1<<' '<<an2<<endl;
			ans1+=an1,ans2+=an2;
		}
		cout<<ans1<<' '<<ans2;
	}else{
		for(int i=1;i<=n;i++)if(a[i+1]!=a[i])ans[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	} 
	return 0;
}
