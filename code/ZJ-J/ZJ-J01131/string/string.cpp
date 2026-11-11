#include<bits/stdc++.h>
#define int long long
using namespace std;
struct qjj{
	int start,end;
	char c;
}a[200005];
int n,num=0,l,r,ans,ansl,ansr,sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x; char y;
		cin>>x>>y;
		if(y==a[num].c)a[num].end+=x;
		else{
			num++;
			a[num].start=a[num-1].end+1;
			a[num].end=a[num-1].end+x;
			a[num].c=y;
		}
	}
	ans=(a[num].end+1)/2;
	for(int i=1;i<=num;i++){
		if(a[i].start<=ans&&a[i].end>=ans){
			l=i,r=i;
			ansr=ans;
			ansl=ans;
			break;
		}
	}
	while(r<=num+1&&l>=0){
		if(ans-a[l].start>a[r].end-ans){
			if(a[l].c!=a[r].c){
				sum+=a[r].end-ansr+1;
			}
			ansl-=a[r].end-ansr+1,ansr=a[r].end+1,r++;
		}
		else{
			if(a[l].c!=a[r].c){
				sum+=ansl-a[l].start+1;
			}
			ansr+=ansl-a[l].start+1,ansl=a[l].start-1,l--;
		}
}
	cout<<sum;
	return 0;
}