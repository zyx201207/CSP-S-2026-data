#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m,nsum=0,maxn=0,maxx=0,sumx=0,fl=1,fp=1;
int a[N],sum1[N],b[N];
string totwo(int n){
	string s="";
	while(n>0){
		if(n%2==1){
			s+='1';
		}
		else{
			s+='0';
		}
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
int anweiyu(string s1,string s2){
	string sp="";
	int sum=0;
	int slen1=s1.size(),slen2=s2.size();
	int slen=max(slen1,slen2);
	if(slen1<slen2){
		reverse(s1.begin(),s1.end());
		for(int i=0;i<slen2-slen1;i++){
			s1+='0';
		}
		
		reverse(s1.begin(),s1.end());
	}
	else if(slen2<slen1){
		reverse(s2.begin(),s2.end());
		for(int i=0;i<slen1-slen2;i++){
			s2+='0';
			
		}
		reverse(s2.begin(),s2.end());
	}
	for(int i=slen-1;i>=0;i--){
		if(s1[i]==s2[i]&&s1[i]=='1'){
			sp+='1';
		}
		else{
			sp+='0';
		}
	}
	reverse(sp.begin(),sp.end()); 
	int q=0;
	for(int i=slen-1;i>=0;i--){
		sum+=(sp[i]-'0')*pow(2,q);
		q++;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	int fl2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<n/2;j++){
			if(pow(2,j)-1==a[i]){
				fl2=1;
				break;
			}
		}
		if(a[i]!=i-1) fp=0;
		if(!fl2) fl=0;
		maxx=max(a[i],maxx);
	}
	if(n==m){
		for(int i=0;i<n;i++){
			if(i!=0){
				sum1[i]=anweiyu(totwo(sum1[i-1]),totwo(a[i]));
			}
			else{
				sum1[i]=a[i];
			}
		}
		cout<<sum1[n-1];
		return 0;
	}
	else if(m==1){
		cout<<maxx;
		return 0;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			sumx=a[i];
			for(int j=0;j<n;j++){
				if(i!=j) sumx=anweiyu(totwo(a[i]),totwo(a[j])); 	
			}
			if(sumx>maxn) maxn=sumx;
		}
		cout<<maxn;
		return 0;
	}
	else if(fl){
		for(int i=0;i<n;i++){
			a[i]=b[i];
		}
		sort(b,b+n);
		cout<<b[m-1];
		return 0;
		
	}
	else if(fp){
		cout<<0;
		return 0;
	}
	return 0;
} 
