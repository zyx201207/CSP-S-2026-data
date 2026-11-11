#include<bits/stdc++.h>
using namespace std;
struct ss{
	long long s;
	char b;
	long long qzh;
};
ss a[200005];
vector<ss> a1,b1;
long long n,sum,ans;
string aa,bb;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].s >> a[i].b;
		sum+=a[i].s;
		a[i].qzh=sum;
	}
	for(int i=1;i<=n;i++){
		if(a[i].b==a[i+1].b){
			a[i+1].s+=a[i].s;
			a[i].s=0;
			a[i].qzh=0;      
		}      
	}                                                                                                                                                                                   
	long long ban=sum/2;
	for(int i=1;i<=n;i++){
		if(a[i].s!=0){
			if(a[i].qzh>ban){
				a[i].s=a[i].qzh-ban;
				b1.push_back(a[i]);
			}else{
				a1.push_back(a[i]);
			}
		}
	}
	for(int i=0;i<a1.size();i++){
		for(int j=0;j<a1[i].s;j++){
			aa+=a1[i].b;
		}
	}
	for(int i=0;i<b1.size();i++){
		for(int j=0;j<b1[i].s;j++){
			bb+=b1[i].b;
		}
	}
	reverse(bb.begin(),bb.end());
	for(int i=0;i<sum;i++){
		if(aa[i]!=bb[i]){
			ans++;
		}
	}
	cout << ans;
	
	
	return 0;
}
