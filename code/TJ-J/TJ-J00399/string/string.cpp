#include <bits/stdc++.h>
using namespace std;
string s;
struct node{
	long long la;
	char ch;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].la>>a[i].ch;
	}
	long long l=1;
	long long r=n;
	long long cnt=0;
	while(l<r){
		if(a[l].la==a[r].la){
			if(a[l].ch==a[r].ch){
				l++;
				r--;
				continue;}
			else {
				 cnt+=a[l].la;
				 l++;
				 r--;
				 continue;
		}}
		if(a[l].la>a[r].la){
			if(a[l].ch==a[r].ch){
				a[l].la-=a[r].la;
				r--;
			}
			else {
				 cnt+=a[r].la;
				 a[l].la-=a[r].la;
				 r--;}
			}
		else {
			if(a[l].ch==a[r].ch){
				a[r].la-=a[l].la;
				l++;
			}
			else {
				cnt+=a[l].la;
				a[r].la-=a[l].la; 
				l++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
