#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;char c;
} ;
int n;long long sum,ans;
node a[200001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<= n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;ans+=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;ans+=a[l].num;
				l++;
			}else{
				ans+=a[l].num;
				l++,r--;
			}
		}
		else{
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}else{
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
