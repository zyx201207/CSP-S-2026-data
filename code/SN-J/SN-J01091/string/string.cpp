#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string q;
	long long n=0,num=0,s=0,lq=0,cs=0;
	char c='0';
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num>>c;
		for(int j=s;j<num;j++){
			q[j]=c;
		}
		s=num;
	}
	lq=q.size();
	long long lqq=lq-1;
	for(int i=0;i<lq/2;i++){
		if(q[lqq]!=q[i]){
			cs++;
		}
		lqq--;
	}
	cout<<cs;
	return 0;
}
