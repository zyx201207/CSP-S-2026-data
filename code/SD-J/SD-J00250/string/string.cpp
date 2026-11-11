#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);//I love CCF
	long long n,a,mi=0;
	string str="";
	string c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			str+=c;
		}
		mi+=a;
	}
	long long k,ans=0;
	bool os;
	if(mi/2==0){
		os=1;
		k=mi/2;
	}else{
		os=0;
		k=mi/2+1;
	}
	for(long long i=mi/2-1;i>=0;i--){
		if(str[i]!=str[k]){
			ans++;
		}
		k++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

