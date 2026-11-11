#include<bits/stdc++.h>

using namespace std;
long long num[200010];
smp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c=0,cnt=0;
	cin>>n>>m;
	for(int i=1;i<+n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1,smp);
	c=num[1];
	if(n==m){
        for(int i=2;i<=n;i++){
		    c=c&num[i];
	        cout<<c;
		}		
	    cout<<c;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				else c=num[i]&num[j];
				cnt=max(c,cnt);
			}
		}
	    cout<<cnt;
	}
	if(m==1){
		cout<<num[1];
	}
	return 0;
}
