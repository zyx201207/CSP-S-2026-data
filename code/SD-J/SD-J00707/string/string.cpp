#include <iostream>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int a;
	char c;
}idx[N];
unsigned long long ans=0;
void js(){
	int l=1,r=n;
	while(l<r){
		if(idx[l].a>idx[r].a){
			if(idx[l].c!=idx[r].c) ans+=idx[r].a;
			idx[l].a-=idx[r].a;
			r--;
		}
		else if(idx[l].a<idx[r].a){
			if(idx[l].c!=idx[r].c) ans+=idx[l].a;
			idx[r].a-=idx[l].a;
			l++;
		}
		else {
			if(idx[l].c!=idx[r].c) ans+=idx[l].a;
			l++;
			r--;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>idx[i].a>>idx[i].c;
	}
	js();
	cout<<ans;
	return 0;
}
