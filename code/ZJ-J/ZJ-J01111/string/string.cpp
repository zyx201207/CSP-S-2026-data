#include<bits/stdc++.h>
using namespace std;
long long n,t,w,ans,a[1000010];char ch[1000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];		
	}
	t=1,w=n;
	while(t<w){
		if(ch[t]!=ch[w]){
			if(a[t]>a[w]){
				a[t]-=a[w];
				ans+=a[w];w--;
			}
			else if(a[t]==a[w]){
				ans+=a[w];
				t++;w--;
			}
			else if(a[t]<a[w]){
				a[w]-=a[t];
				ans+=a[t];t++;
			}
		}
		else if(ch[t]==ch[w]){
			if(a[t]>a[w]){
				a[t]-=a[w];w--;
			}
			else if(a[t]==a[w]){
				t++;w--;
			}
			else if(a[t]<a[w]){
				a[w]-=a[t];t++;
			}
		}
	}
	cout<<ans;
    return 0;
}