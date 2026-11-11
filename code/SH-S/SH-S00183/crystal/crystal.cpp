#include<bits/stdc++.h>
using namespace std;
long long a[500005]; 
queue<int> choice;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1,cost=0,cv=a[1];
	for(int i=2;i<=n;i++){
		if(cost+(a[i]-cv)*ans<=m){
			cost+=(a[i]-cv)*ans;
			choice.push(i);
			ans++;
			cv=a[i];
		}else{
			int c=choice.front();
			if(cv-a[c]>(a[i]-cv)*(ans-1)){
				choice.pop();
				cost-=(cv-a[c]-(a[i]-cv)*(ans-1));
				if(cost+(a[i]-cv)*(ans-1)<=m){
					cost+=(a[i]-cv)*ans;
					choice.push(i);
					cv=a[i];
				}
				else ans--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
