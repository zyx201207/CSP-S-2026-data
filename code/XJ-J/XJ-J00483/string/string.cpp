#include<bits\stdc++.h>
using namespace std;
int main(){
	    	        freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string str;
    int tim(0);
    cin>>tim;
    int n = 0;
    for(int i(0);i<tim;i++){
    	int tim_1 = 0;
    	char a = '0';
    	cin>>tim_1>>a;
    	for(int j(0);j<tim_1;j++){
    		str += a;
	}}
    for(int i(0);i<str.length();i++){
    	if(str[i] != str[str.length()-1-i]){
    		
    		str[str.length()-1-i] = str[i];
    		n++;
		}
	}
    cout<<n;
}