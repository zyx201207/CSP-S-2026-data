#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long l;
	char ch;
}s[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%ld",&s[i].l);
		cin>>s[i].ch;
	}
	int i=0,j=n-1;
	while(i<j){
		if(s[i].ch!=s[j].ch){
			sum=sum+min(s[j].l,s[i].l);
			if(s[i].l==s[j].l){
				i++;
				j--;
			}
			else if(s[i].l<s[j].l){
				s[j].l=s[j].l-s[i].l;
				i++;
			}
			else{
				s[i].l=s[i].l-s[j].l;
				j--;
			}
		}
		else{
			if(s[i].l==s[j].l){
				i++;
				j--;
			}
			else if(s[i].l<s[j].l){
				s[j].l=s[j].l-s[i].l;
				i++;
			}
			else{
				s[i].l=s[i].l-s[j].l;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}

