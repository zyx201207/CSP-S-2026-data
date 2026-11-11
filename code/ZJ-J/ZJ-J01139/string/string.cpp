#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,t,w,l1,l2,ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	t=1,w=n;
	l1=0,l2=0;
	while(t<w){
		if(s[t]!=s[w]){
			if(a[t]-l1>a[w]-l2){
				l1+=(a[w]-l2);
				ans+=(a[w]-l2);
				w--;
				l2=0;
			}else if(a[t]-l1<a[w]-l2){
				l2+=(a[t]-l1);
				ans+=(a[t]-l1);
				t++;
				l1=0;
			}else if(a[t]-l1==a[w]-l2){
				ans+=(a[t]-l1);
				l1=0,l2=0;
				t++,w--;
			}
		}else{
			if(a[t]-l1>a[w]-l2){
				l1+=(a[w]-l2);
				w--;
				l2=0;
			}else if(a[t]-l1<a[w]-l2){
				l2+=(a[t]-l1);
				t++;
				l1=0;
			}else if(a[t]-l1==a[w]-l2){
				l1=0,l2=0;
				t++,w--;
			}
		}
	}
	cout<<ans;
	return 0;
}