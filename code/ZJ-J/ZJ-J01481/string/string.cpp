#include<bits/stdc++.h>
using namespace std;
int n,t,w;
long long s,ks;
struct sl{
	int a;
	string s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
		ks+=a[i].a;
	}
	t=1;
	w=n;
	ks=(ks+1)/2;
	while(t<w){
		if(a[t].s==a[w].s){
			if(a[t].a>a[w].a){
				a[t].a-=a[w].a;
				w--;
			}else if(a[t].a<a[w].a){
				a[w].a-=a[t].a;
				t++;
			}else if(a[t].a==a[w].a){
				t++;
				w--;
			}
		}else{
			if(a[t].a>a[w].a){
				s+=a[w].a;
				a[t].a-=a[w].a;
				w--;
			}else if(a[t].a<a[w].a){
				s+=a[t].a;
				a[w].a-=a[t].a;
				t++;
			}else if(a[t].a==a[w].a){
				s+=a[t].a;
				t++;
				w--;
			}
		}
	}
	cout<<s;
	return 0;
}
