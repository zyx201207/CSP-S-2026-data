#include<iostream>
using namespace std;
struct aa{
	int a;
	char c;
}t[200001],a[200001],b[200001],t1,t2;
long long n,s,c,l,n1,n2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i].a>>t[i].c;
		s+=t[i].a;
	}
	s/=2;
	for(int i=0;i<n;i++){
		if(l+t[i].a<=s){
			l+=t[i].a;
			a[n1++]=t[i];
			if(l==s){
				break;
			}
		}else{
			a[n1].a=s-l;
			a[n1++].c=t[i].c;
			break;
		}
	}
	l=0;
	for(int i=n-1;i>0;i--){
		if(l+t[i].a<=s){
			l+=t[i].a;
			b[n2++]=t[i];
			if(l==s){
				break;
			}
		}else{
			b[n2].a=s-l;
			b[n2++].c=t[i].c;
			break;
		}
	}
	int i=0,j=0;
	t1=a[i];
	t2=b[j];
	while(i<n1&&j<n2){
		if(t1.c!=t2.c){
			if(t1.a==t2.a){
				c+=t1.a;
				i++;
				if(i<n1){
					t1=a[i];
				}
				j++;
				if(j<n2){
					t2=b[j];
				}
			}else if(t1.a<t2.a){
				c+=t1.a;
				t2.a-=t1.a;
				i++;
				if(i<n1){
					t1=a[i];
				}
			}else if(t1.a>t2.a){
				c+=t2.a;
				t1.a-=t2.a;
				j++;
				if(j<n2){
					t2=b[j];
				}
			}
		}else{
			if(t1.a==t2.a){
				i++;
				if(i<n1){
					t1=a[i];
				}
				j++;
				if(j<n2){
					t2=b[j];
				}
			}else if(t1.a<t2.a){
				t2.a-=t1.a;
				i++;
				if(i<n1){
					t1=a[i];
				}
			}else if(t1.a>t2.a){
				t1.a-=t2.a;
				j++;
				if(j<n2){
					t2=b[j];
				}
			}
		}
	}
	cout<<c;
	return 0;
}
