#include<bits/stdc++.h>
using namespace std;
int n,m;
long long str[10000005],strb,cnt;
char st[10000005];
char s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		scanf("%d %c",&m,&s);
		str[strb]=m;
		st[strb]=s;
		strb++;
	}
	long long left=0,right=strb;
	while(left<=right){
		if(str[left]==str[right]){
			if(st[left]!=st[right]) cnt+=str[left];
			left++;
			right--;
		}
		 else if(str[left]>str[right]){
			if(st[left]!=st[right]) cnt+=str[right];
			str[left]-=str[right];
			right--;
		}
		else if(str[left]<str[right]){
			if(st[left]!=st[right]) cnt+=str[left];
			str[right]-=str[left];
			left++;
		}
	}
	cout<<cnt;
	return 0;
}


