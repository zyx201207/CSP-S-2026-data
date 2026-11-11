#include<bits/stdc++.h>
using namespace std;
int n;
struct k{
	long long cnt;
	char c;
}a[1000001];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
	}
	int i=1,j=n;
	while(i<j){
		int sz1=a[i].cnt,sz2=a[j].cnt;
		if(sz1>sz2){
			if(a[i].c!=a[j].c){
				sum+=a[j].cnt;
			}
			a[i].cnt-=a[j].cnt;
			j--;
		}else if(sz1<sz2){
			if(a[i].c!=a[j].c){
				sum+=a[i].cnt;
			}
			a[j].cnt-=a[i].cnt;
			i++;
		}else{
			if(a[i].c!=a[j].c) sum+=a[j].cnt;
			i++;
			j--;
		}
	}
	cout<<sum;
	return 0;
}