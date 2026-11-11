#include<bits/stdc++.h>
using namespace std;
int n,a[200200],le,res;
char c[200200];
vector<char> s;
//must delete the //////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	s.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		le+=a[i];
		for(int j=1;j<=a[i];j++)
			s.push_back(c[i]);
		
	}
	if(le<3){//le==1或2就一定是回文串 
		cout<<0;
		return 0;
	}
	int left,right;
	if(le%2==0){//le是偶数 
		left=le/2;
		right=le/2+1;
	}else{//le是奇数 
		left=le/2;
		right=le/2+2;
	}
	while(left>=1&&right<=le){
		char nowa=s[left],nowc=s[right];
		
		//获取当前的a和c
		/*
		long long l=0,r=le;
		int i=1;
		for(;;i++){
			if(l+a[i]>left){
				while(l!=a[i]) l++;
				break;
			}
			l+=a[i];
		}
		for(;;i++){
			if()
		}
		
		*/
		
		if(nowa!=nowc) res++;
		left--;
		right++;
	}
	cout<<res;
	
	return 0;
}
