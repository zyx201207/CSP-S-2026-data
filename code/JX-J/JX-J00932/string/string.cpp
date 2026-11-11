#include <bits/stdc++.h>

using namespace std;

bool pd(string b){
	string a="";
	int len=b.size();
	for(int i=len-1;i>=0;i--){
		a=a+b[i];
	}
	if(a==b) return 1;
	return 0;
}

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	string x="";
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			x=x+c;
		}
	}
	if(pd(x)==1) cout<<0;
	else{
		int lenx=x.size();
		if(lenx%2==1){
			int ans1=0,ans2=0;
			string a="",b="";
			for(int i=0;i<lenx/2;i++) {
				a=a+x[i];
				
			}
			for(int i=lenx-1,j=0;i>=lenx/2+1;i--,j++){
				if(a[j]!=x[i]) ans1++;
				b=b+x[i];
			}
			for(int i=0;i<lenx/2;i++){
				if(b[i]!=x[i]) ans2++;
				
			}
			cout<<min(ans1,ans2);
			return 0;
		}
		else{
			int ans1=0,ans2=0;
			string a="",b="";
			for(int i=0;i<lenx/2;i++) {
				a=a+x[i];
				
			}
			for(int i=lenx-1,j=0;i>=lenx/2;i--,j++){
				if(a[j]!=x[i]) ans1++;
				b=b+x[i];
				
			}
			for(int i=0;i<lenx/2;i++){
				if(b[i]!=x[i]) ans2++;
			}
			cout<<min(ans1,ans2);
			return 0;
		}
	}
	return 0;
}
