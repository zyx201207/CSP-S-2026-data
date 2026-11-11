#include<bits/stdc++.h>
using namespace std;
struct st{
	long long num;
	string cha;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long ans=0;
	cin>>n;
	vector<st> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].cha;
	}
	while(!a.empty() && a.size()>1){
		int y=min(a[0].num,a[n-1].num);
		if(a[0].cha==a[n-1].cha){
			a[0].num-=y;
			a[n-1].num-=y;
			if(a[0].num==0){
				a.erase(a.begin()+0);
				n--;
			}
			else if(a[n-1].num==0){
				a.erase(a.begin()+n-1);
				n--;
			}
		}else{
			ans+=y;
			a[0].num-=y;
			a[n-1].num-=y;
			if(a[0].num==0){
				a.erase(a.begin()+0);
				n--;
			}
			else if(a[n-1].num==0){
				a.erase(a.begin()+n-1);
				n--;
			}
		}
	}
	cout<<ans;
	return 0;
}
