#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
struct node{
	char key;
	long long val;
};
node p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].val>>p[i].key;
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<r){
		bool f=(p[l].key!=p[r].key);
		if(p[l].val>p[r].val){
			if(f) ans+=p[r].val;
			p[l].val-=p[r].val;
			p[r].val=0;
			r--;
		}else if(p[l].val==p[r].val){
			if(f) ans+=p[r].val;
			p[r].val=0;
			p[l].val=0;
			l++;
			r--;
		}else{
			if(f) ans+=p[l].val;
			p[r].val-=p[l].val;
			p[l].val=0;
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
