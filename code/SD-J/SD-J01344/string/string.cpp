#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
char c[N];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=0,r=n-1;
	int tl=a[l],tr=a[r];
	while(l<r){
		long long minn=min(tl,tr);
		if(c[l]!=c[r]){
			cnt+=minn;
		}
		if(tl==tr){
			l++;
			r--;
			if(l<=r){
				tl=a[l];
				tr=a[r];
			}
		}
		else if(tl>tr){
			tl-=tr;
			r--;
			tr=a[r];
		}
		else{
			tr-=tl;
			l++;
			tl=a[l];
		}
	}
	cout<<cnt;
	return 0;
}
//why to re on test 6?
//test 6 跑不出来是hyw
//AC pls
