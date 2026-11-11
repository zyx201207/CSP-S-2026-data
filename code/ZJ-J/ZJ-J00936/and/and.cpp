#include<bits/stdc++.h>
using namespace std;
int n,m,w=29,ans=0;
int a1[35];
long long a[200005];
string b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	int x=a[i];
    	for (int j=1;j<=30;j++){
    		if(x%2==1){
    			b[i]+='1';
			}else{
				b[i]+='0';
			}
    		x/=2;
		}
	}
	b[0]="00000000000000000000000000000";
	a1[30]=0;
	for (int i=29;i>=0;i--){
		a1[i]=0;
		if(a1[i+1]>=m){
			for (int j=1;j<=n;j++){
				if(b[j][i+1]!='1'){
					j1[j]==0;
				}
			}
		}
		for (int j=1;j<=n;j++){
			if(b[j][i]=='1'){
				a1[i]++;
			}
		}
		if(a1[i]>=m){
			int wnd=1;
			for (int j=i;j>0;j--){
				wnd*=2;
			}
			ans+=wnd;
		}
	}
	cout<<ans;
	return 0;
}