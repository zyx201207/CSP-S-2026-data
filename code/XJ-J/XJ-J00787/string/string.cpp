#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[100001];
	int n,j=0,ss=0,cc=0;
	cin>>n;
	for(int i=0;i<n;i++){
		char s1;
		int a;
		cin>>a;
		cin>>s1;
		for(int h=1;h<=a;h++){
			s[j]=s1;
			j++;
			ss++;
		}
	}
	while(1){
		int b=1,c=1;
		for(int i=0;i*2<ss;i++){
			if(c!=1){
				break;
			}
			if(s[i]!=s[ss-b])c=0;
			else b++;
		}
		b=1;
		if(c!=1){
			for(int i=0;i*2<ss;i++){
				if(s[i]!=s[ss-b]){
					s[ss-b]=s[i];
					cc++;
					b++;
				}
				else {
					b++;
				}
			}
		}
		else break;
	}
	cout<<cc;
	fclose(stdin);
	fclose(stdout);
	return 0;
}