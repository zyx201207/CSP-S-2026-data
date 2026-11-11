#include<iostream>
using namespace std;
struct S{
	long long a,b;
	char c;
}q[200010];
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,a,k=0;
	cin>>n;
	char c;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		q[k++]={l,l+a-1,c};
		l+=a;
	}
	a=0;
	l--;
	long long ans=0,h=0;
	k--;
	while(a<l){
		if(q[h].c!=q[k].c){
			ans++;
		}
		a++;
		l--;
		if(a>q[h].b){
			h++;
		}
		if(l<q[k].a){
			k--;
		}
	}
	cout<<ans;
	return 0; 
} 
