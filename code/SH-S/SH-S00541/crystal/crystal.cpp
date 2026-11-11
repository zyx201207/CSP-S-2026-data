#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	bool flag=true;
	cin>>n>>m;
	int a[500005];
	vector<int> cnt(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=false; 
	}
	if(flag){
		int crystal=(8*m+9);
		cout<<(crystal-1)/2<<"\n";
		return 0;
	}
	sort(a,a+n);
	for(int jizhun=1;jizhun<n;jizhun++){
		int x=a[jizhun];
		for(int j=0;j<jizhun;j++){
			if(m>0){
				int s=x-a[j];
				a[j]+=s;
				m-=s;
			}
			else{
				break;
			}
		}
		for(int k=0;k<n;k++){
			if(a[k]==x) cnt[jizhun]++;
		}
	} 
	int maxx=-1e9;
	for(int i=0;i<n;i++){
		maxx=max(maxx,cnt[i]);
	}
	cout<<maxx<<endl;
	return 0;
} 
