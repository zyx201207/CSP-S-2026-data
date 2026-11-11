#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long a,j=0;
    char b;
    string s;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        for(int q=0;q<a;q++){
        s[j]=b;
        j++;
        }
    }
    long sum=0;
    for(int i=0;i<j/2;i++){
		if(s[i]!=s[j-1-i]) sum++;
	}
	cout<<sum;
   return 0;
}
