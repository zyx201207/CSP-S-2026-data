#include<bits/stdc++.h>
using namespace std;
int cnt[100000];
int n,m;
queue<int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mmin=100001;
	int mmax=-100001;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
		if(x<mmin)
		mmin=x;
		if(x>mmax)
		mmax=x;
	}
	int a[n+1];
	for(int i=1;i<=n;i++)
	a[i]=0;
	
	int ans=0;
	int num=0;
	for(int i=mmin;i<=mmax;i++){
		for(int j=1;j<=cnt[i];j++){
			q.push(i);
			num+=i;
			int num2=q.size();
			if(num+m>=num2*i){
				ans=max(ans,num2);
			}
			else{
				num-=q.front();
				q.pop();
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
