#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
vector<int> s[50];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//我献祭林老师一亿根头发换AC 
	//我献祭周扬合一万根头发换AC
	//我献祭GH一米身高换AC
	//CSP为什么不帮考生处理好数据?
	//因为他很CS 
	cin>>n>>m;
	//cout<<1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<1/2;
	sort(a+1,a+1+n,cmp);
	long long x,d;
	for(int i=1;i<=n;i++){
		x=a[i];
		d=1;
		while(x>0){
			if(x%2==1){
				s[d].push_back(a[i]);
			}
			d++;
			x/=2;
		}
	}
	int man=-1;
//	for(int i=6;i>=1;i--){
//		for(int j=0;j<s[i].size();j++){
//			cout<<s[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=49;i>=1;i--){
		if(s[i].size()>=m){
			//cout<<s[i].size()<<" ";
			man=i;
			break;
		}
	}
	if(man==-1){
		cout<<0;
		return 0;
	}else{
		long long ans=s[man][0];
		for(int i=0;i<m;i++){
			//cout<<ans<<" "<<s[man][i]<<endl;
			ans=(ans&s[man][i]);
		}
		//cout<<54188;
		cout<<ans;
	}
	
	return 0;
}
