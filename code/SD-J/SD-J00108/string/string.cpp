#include <bits/stdc++.h>
using namespace std;
int t;bool flag;long long ans=0;
int l=0,r;
struct Node{
	long long x;
	char y;
}m[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;r=t-1;
	for(int i=0;i<t;i++){
		cin>>m[i].x>>m[i].y;
	}
	Node a={m[0].x,m[0].y};
	flag=false;
	while(l<=r){
		if(!flag){
			if(a.y==m[r].y){
				if(a.x>m[r].x){
					a.x=a.x-m[r].x;
					r--;
				}
				else if(a.x<m[r].x){
					a.x=m[r].x-a.x;
					flag=true;l++;}
				else{
					l++;r--;
					a.x=m[l].x;
					a.y=m[l].y;
				}
			}
			else{
				ans+=min(a.x,m[r].x);
				if(a.x>m[r].x){
					a.x=a.x-m[r].x;
					r--;
				}
				else if(a.x<m[r].x){
					a.x=m[r].x-a.x;
					a.y=m[r].y;
					flag=true;
					l++;
				}
				else{
					l++;r--;
					a.x=m[l].x;
					a.y=m[l].y;
				}
			}
		}
		else{
			if(a.y==m[l].y){
				if(a.x>m[l].x){
					a.x=a.x-m[l].x;
					l++;
				}
				else if(a.x<m[l].x){
					a.x=m[l].x-a.x;
					flag=false;r--;}
				else{
					l++;r--;
					a.x=m[l].x;
					a.y=m[l].y;
				}
			}
			else{
				ans+=min(a.x,m[l].x);
				if(a.x>m[l].x){
					a.x=a.x-m[l].x;
					l++;
				}
				else if(a.x<m[l].x){
					a.x=m[l].x-a.x;
					a.y=m[l].y;
					flag=false;
					r--;
				}
				else{
					l++;r--;
					a.x=m[l].x;
					a.y=m[l].y;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
