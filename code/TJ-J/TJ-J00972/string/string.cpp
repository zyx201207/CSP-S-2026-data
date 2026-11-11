#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int len=0;
    for(int i=0;i<n;i++){
    	int a;
    	char c;
    	cin>>a>>c;
    	len+=a;
    	for(int i=0;i<a;i++){
    		s+=c;
		}
	}
	int num=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			s[len-i-1]=s[i];
			num++;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
