#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for (int i=0;i<n;i++){
		int a1;
		string c;
		cin>>a1>>c;
		for (int j=0;j<a1;j++){
			s+=c;
		}
	}//ÕÒµ½×Ö·û´®s
	int num=0;
	int len=s.length();
	int a[len];
	for (int i=0;i<len;i++){
			a[i]=s[i]-'0';
	}//´æµ½a
	long long j=len-1;
	if (len%2==0){
		for (int i=0;i<len/2;i++){//×ó
			if (a[i]!=a[j]){
				num++;
			}
			j--;
		}
	}else if (len%2==1){
		for (int i=0;i<=s.length()/2;i++){
//			cout<<"55";
			if (a[i]!=a[j]){
				num++;
			}
			j--;
		}
	}
	int c[10005]={0};
	int i=0;
	if (num==0){
		cout<<"0";
		return 0;
	}
	while (num){
		c[i]=num%10;
		num/=10;
		i++;
	}
//	cout<<s;5/2=2!!!!!!!
	for (int k=0;k<i;k++){
		cout<<c[k];
	}
//	cout<<num;
	return 0;
}
