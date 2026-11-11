#include<bits/stdc++.h>
using namespace std;
struct zf{
	long long a;
	char c;
};
zf q[200005];
int main(){
	freopen("string.in", "r",stdin);
	freopen("string.out", "w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i].a>>q[i].c;
	}
	int i=0,j=n-1;
	long long z=0;
	while(i<j){
		long long t;
		if(q[i].a>q[j].a){
			t=q[j].a;
		}
		else{
			t=q[i].a;
		}
		if(q[i].c!=q[j].c){
			z+=t;
			q[i].a-=t;
			q[j].a-=t;
			if(q[i].a==0){
				i++;
			}
			if(q[j].a==0){
				j--;
			}
		}
		else{
			q[i].a-=t;
			q[j].a-=t;
			if(q[i].a==0){
				i++;
			}
			if(q[j].a==0){
				j--;
			}
		}
	}
	cout<<z;
	return 0;
}
