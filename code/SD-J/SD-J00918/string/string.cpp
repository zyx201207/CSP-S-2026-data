#include<bits/stdc++.h>
using namespace std;
#define int long long
struct b{
	int shu;
	string s1;
};
b w[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	long long num1=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>s;
		w[i].s1=s;
		w[i].shu=a;
	}
	int l=n;
	for(int i=1;i<l;i++){
		while(w[i].shu!=0){
			int m=min(w[i].shu,w[l].shu);
			w[i].shu-=m;
			w[l].shu-=m;
			if(w[i].s1!=w[l].s1){
				num1+=m;
			}
			if(w[l].shu==0){
				l--;
			}
		}
	}
	cout<<num1;
	
	return 0;
}
