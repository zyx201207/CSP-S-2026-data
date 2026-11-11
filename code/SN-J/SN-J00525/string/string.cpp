#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f=99999999,g,h=-99999;
char bb;
pair<long long,char> aa[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b>>bb;
		
		aa[i].first=g;
		aa[i].second=bb;
		g+=b;
	}
	for(long long i=0;i<(g+1)/2;i++){
		e=g-i-1;//e回文数对应
		//f aa数组中对应的数字 
		if(f==99999999){
			for(int j=a-1;j>=0;j--){
				if(aa[j].first<=e){
					f=j;
					break;
				}
			}
		}else if(aa[f].first>=e){
			for(int j=a-1;j>=0;j--){
				if(aa[j].first<=e){
					f=j;
					break;
				}
			}
		}
		if(h<0){
			for(int j=0;j<a;j++){
				if(aa[j].first==i){
					h=j;
					break;
				}
				if(aa[j].first>i){
					h=j-1;
					break;
				}
			}
		}else if(aa[h].first<i){
			for(int j=0;j<a;j++){
				if(aa[j].first==i){
					h=j;
					break;
				}
				if(aa[j].first>i){
					h=j-1;
					break;
				}
			}
		}
		//cout<<aa[f].first<<" "<<aa[f].second<<" "<<aa[h].first<<" "<<aa[h].second<<" "<<d<<endl;
		if(aa[f].second!=aa[h].second){
			d++;
			//cout<<i<<" "<<e<<" "<<f<<" "<<h<<endl;
		}
		//cout<<e<<" "<<f<<" "<<d<<endl;
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

