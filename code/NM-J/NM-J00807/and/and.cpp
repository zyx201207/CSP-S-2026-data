#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0,an=0;
	cin>>n>>m;
	vector <long long> num;
	vector <string> str; 
	vector <string> s;
	for(int i=0;i<n;i++){
		long long t=0;
		cin>>t;
		long long pl=t;
		string a="\0";
		
		while(true){
			int tem=pl%2;
			pl/=2;
//			cout<<tem<<"\n"<<pl<<"\n";
			char q=tem+'0';
			a+=q;
			if(pl==0){
				break;
			}
		}
		string b="\0";
		s.push_back(a);
		for(int i=0;i<a.length();i++){
			b+=a[a.length()-i-1];
		}
		str.push_back(b);
	}
	
	string tem=str[0],aa="\0";
	for(int i=1;i<str.size();i++){
		string rp=str[i];
		for(int j=0;j<max(rp.length(),tem.length());j++){
			if(rp[j]==tem[j]){
				aa+="1";
			}else{
				aa+="0";
			}
			
		}
		tem=aa;
		aa="\0";
	}
	long long ten=1,k=1;
	string im="\0";
	for(int i=0;i<tem.length();i++){
		im=im+tem[tem.length()-i-1];
	}
	cout<<im<<"\n";
	for(int i=0;i<im.length();i++){
		int q=im[i]-'0';
		an+=q*k;
		k*=2;
	}
	cout<<an;
	return 0;
}
