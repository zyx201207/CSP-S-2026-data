#include<bits/stdc++.h>
#include<string>
using namespace std;
int const m=100000005;
int a[m];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string c,s;
	int record=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		record=a[i];
		for(int j=1;j<=record;j++){
			s+=c;
		}
	} 
	int sum=0;
	int l=1;
	int r=s.size();
	for(int i=1;i<=s.size;i++){
	    if(l>=r){
		    cout<<sum;
		    return 0;
	    }else{
		    if(s[l]<s[r]){
			    if(s[l]!=s[r]){
			        s[r]=s[l];
			        sum++;
		        }
		    }
	    }
    }
	cout<<sum;
	return 0;
}
