#include<bits/stdc++.h>
using namespace std;
int n,i,w,t,a[200100];
char c[200100];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}t=1;w=n;
	while(t<=w){
		if(c[t]!=c[w]){
			if(a[t]>a[w]){
				a[t]-=a[w];
				ans+=a[w];
				a[w]=0;
				w--;
			}else{
				a[w]-=a[t];
				ans+=a[t];
				a[t]=0;
				t++;
			}
		}else{
			if(a[t]>a[w]){
				a[t]-=a[w];
				a[w]=0;
				w--;
			}else{
				a[w]-=a[t];
				a[t]=0;
				t++;
			}
		}//cout<<t<<" "<<w<<" "<<ans<<"\n";
	}cout<<ans<<"\n";
	return 0;
}
