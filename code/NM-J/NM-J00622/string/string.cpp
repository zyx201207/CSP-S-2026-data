#include<bits/stdc++.h>
using namespace std;

long long n,c,k;
long long a[100010];
char b[100010];
string s="",t="";

bool huiwen(string s1)
{
	string r="";
	for(int i=0;i<s1.size();i++){
		r+=s1[s1.size()-1-i];
	}
	if(r==s1){
		return true;
	}
	return false;
}

int main()
{
    //4444444444444444444444444444444444444444444444444444444444444
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        fill(s.begin()+k,s.begin()+(k+a[i]),b[i]);
        k+=a[i];
    }

    for(int i=0;i<k/2;i++)
	{
    	t+=s[i];
	}

	for(int i=0;i<k/2;i++)
	{
    	if(s[k-i] != t[i]){
    		c++;
		}
	}
	if(huiwen(s)){
		cout<<0;
	}else{
		cout<<c;
	}


    return 0;
}
