#include<bits/stdc++.h>
using namespace std;
long long n,x,sum;
string a,b,x1,x2;
bool hw(string x,string y){
    string z;
    for(long long i=y.size()-1;i>=0;i--){
    	z+=y[i]; 
	}
    return x==z;
} 
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool f=1;
    for(long long i=1;i<=n;i++){
    	cin>>x;
    	cin>>a;
    	for(long long j=1;j<=x;j++){
    		b+=a;
		}
	}string c="";
	int fl=0;
	for(long long i=0;i<b.size()-1;i++){
		if(b[i]==b[i+1]){
			fl=1;
		}else{
			fl=0;
		}
	if(fl==1){
		cout<<0;
		return 0;
	}
	}int xx=b.size()/2;
	int j=0;
	x1="";x2="";
	for(long long i=0;i<xx;i++){
	    	x1+=b[i];
		}
	for(long long i=xx;i<b.size();i++){
			x2+=b[i];
		}
	j=0;
	while(hw(x1,x2)){
		swap(x1[j],x2[b.size()-j]);
	    j++; 
		sum++;
    }
    cout<<sum*2;
	return 0;
}
