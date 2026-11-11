#include<bits/stdc++.h>
using namespace std;
vector<long long> aa;
vector<char> bb;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long a;
	char b;
	cin>>n;
	aa.push_back(0);
	bb.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		aa.push_back(a);
		bb.push_back(b);
	}
	int l=1,r=n;
	long long tl,tr,flag;
	tl=aa[l],tr=aa[r];
	while(l<r){
		if(bb[l]==bb[r]){
			flag=0;
		}else{
			flag=1;
		}
		if(tl>tr){
			tl-=tr;
			ans+=flag*tr;
			tr=0;
			r--;
			tr=aa[r];
		}else if(tl<tr){
			tr-=tl;
			ans+=flag*tl;
			tl=0;
			l++;
			tl=aa[l];
		}else{
			l++;
			r--;
			ans+=flag*tr;
			tr=aa[r];
			tl=aa[l];
		}
	}
	cout<<ans;
	return 0;
} 