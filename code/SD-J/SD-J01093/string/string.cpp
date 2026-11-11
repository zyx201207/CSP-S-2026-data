#include<bits/stdc++.h>
using namespace std;
struct node{
	long long c;
	string s;
}a[200500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].s;
	}
	long long j=n,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].s==a[j].s){
			if(a[j].c<a[i].c){
				if(a[j].s==a[i].s){
					j--;
					continue;
				}
				cnt+=abs(a[i].c-a[j].c);
				a[j-1].c=a[j-1].c-abs(a[i].c-a[j].c);
				a[j].c=a[j].c+abs(a[i].c-a[j].c);
			}else{
				if(a[j].s==a[i].s){
					j--;
					continue;
				}
				cnt+=abs(a[i].c-a[j].c);
				a[i-1].c=a[i-1].c-abs(a[i].c-a[j].c);
				a[i].c=a[i].c+abs(a[i].c-a[j].c);
			}
		}else{
			if(a[j].c<a[i].c){
				if(a[j].s==a[i].s){
					j--;
					continue;
				}
				cnt+=max(a[i].c,a[j].c);
				a[j-1].c=a[j-1].c-abs(a[i].c-a[j].c);
				a[j].s=a[i].s;
				a[j].c=a[j].c+abs(a[i].c-a[j].c);
			}else{
				if(a[j].s==a[i].s){
					j--;
					continue;
				}
				cnt+=min(a[i].c,a[j].c);
				a[i-1].c=a[i-1].c-abs(a[i].c-a[j].c);
				a[i].s=a[j].s;
				a[i].c=a[i].c+abs(a[i].c-a[j].c);
			}
			
		}
		j--;
	}
	cout<<cnt;
	return 0;
}
