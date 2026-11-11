#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long maxn=0;

int qwe(int now,int u,int p){
	int nowmax=0;
	if(u>=m-1){
		return now;
	}else{
		for(int i=p+1;i<n;i++){
			if(nowmax<(a[i]&now)){
				nowmax=(a[i]&now);
				p=i;
			}
		}
		return qwe(nowmax,u+1,p);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(maxn<qwe(a[i],0,i)){
			maxn=qwe(a[i],0,i);
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}