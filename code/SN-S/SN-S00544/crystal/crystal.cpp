#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int>num;
#define int long long
vector<int>vs;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vs.push_back(k);
	}
	sort(vs.begin(),vs.end());
	for(int i=0;i<n;i++){
		int Max=0;
		vector<int>num={0};
		for(int j=0;j<=i;j++){
			num.push_back(vs[i]-vs[j]);
		}
		sort(num.begin(),num.end());
		int number=0;
		for(int j=0;j<=i;j++){
			number+=num[j];
			if(number>m){
				Max=j;
				break; 	
			}
		}
		if(Max==0)Max=i+1;
		ans=max(Max,ans);
	}
	cout<<ans-1;
	return 0;
}
