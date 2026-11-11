#include<iostream>
using namespace std;
int n,m,aa,ans,si,e=1,b[200005],se;
bool a[200005][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa;
		int len=1;
		while(aa){
			if(aa%2==1){
				a[i][len]=1;
			}
			len++;
			aa/=2;
		}
		a[i][0]=1;
	}
	for(int i=1;i<=30;i++){
		e*=2;
	}
	for(int i=31;i>=1;i--){
		si=0,se=0;
		for(int j=1;j<=n;j++){
			if(a[j][0]==0){
				continue;
			}
			if(a[j][i]==1){
				si++;
			}
			else{
				b[++se]=j;
			}
		}
		if(si>=m){
			ans+=e;
			for(int j=1;j<=se;j++){
				a[b[j]][0]=0;
			}
		}
		e/=2;
	}
	cout<<ans;
	return 0;
}
//csp 2026 rp++
