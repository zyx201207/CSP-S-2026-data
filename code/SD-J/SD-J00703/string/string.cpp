#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
struct node{
	int cnt,vis; 
	char c;
}a[N];
ll n,cha,j,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	j=n;
	int i=1;
	for(int k=1;k<=n;k++){
		cin>>a[k].cnt>>a[k].c;
	}
	while(j>=i){
		if(a[i].vis||a[j].vis){
			break;
		}
		else{
			if(a[i].c==a[j].c){
				if(a[i].cnt>a[j].cnt){
					a[i].cnt-=a[j].cnt;
					a[j].cnt=0;
					a[j].vis=1;
					j--;
				}
				else if(a[i].cnt<a[j].cnt){
					a[j].cnt-=a[i].cnt;
					a[i].cnt=0;
					a[i].vis=1;
					i++;
				}
				else{
					i++;
					j--;
				}
			}
			else{
				if(a[i].cnt>a[j].cnt){
					ans+=a[j].cnt;
					a[i].cnt-=a[j].cnt;
					a[j].cnt=0;
					a[j].vis=1;
					j--;
				}
				else{
					ans+=a[i].cnt;
					a[j].cnt-=a[i].cnt;
					a[i].cnt=0;
					a[i].vis=1;
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
