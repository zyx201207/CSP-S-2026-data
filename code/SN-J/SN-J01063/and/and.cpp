#include<bits/stdc++.h>
using namespace std;
string jinzhi(long long a){
	string m;
	while(a){
		long long n=a/2;
		if(n*2==a) m+='0';
		else m+='1';
		a/=2;
	}
	string M; 
	for(int i=m.size()-1;i>=0;i--){
		M+=m[i];
	}
	return M;
}
string For(string a,string b){
	string n;
	int j=b.size()-1;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]==b[j]) n+='1';
		else n+='0';
		j++;
	}
	string R;
	for(int i=n.size()-1;i>=0;i--){
		R+=n[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long n[10001]; 
    //long long MAXX=-1,MAXX_1=-1;
    for(long long i=0;i<a;i++){
    	cin>>n[i];
    }
    for(long long i=0;i<a-1;i++){
    	for(long long j=i+1;j<a;j++){
    		if(n[i]<n[j]) swap(n[i],n[j]);
		}
	}
	long long m[10001];
	for(long long i=0;i<a;i++) m[i]=n[i];
	string L[10001]; 
	for(long long i=0;i<a;i++){
		L[i]=jinzhi(n[i]);
	}
	string P;
	for(long long i=0;i<a;i++){
		if(i==0){
			P=For(L[i],L[i+1]);
			i=1;
		}else{
			P=For(P,L[i]);
		}
	}
	long long ans=0,j=0;
	if(P[P.size()-1]=='1') ans+=1;
	string O;
	for(int i=P.size()-1;i>=0;i--){
		O+=P[i];
	}
	//for(int )
	for(long long i=1;i<=O.size()-1;i++){
		//long long ans1=1;
		long long B=2;
		if(P[i]=='1'){
			for(int i=1;i<=i;i++){
				B*=2;
			}
		}
		ans+=B;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout); 
	return 0;
} 
