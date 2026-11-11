#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx_a=-1,allanweiyu;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0) allanweiyu=a[i];
		else allanweiyu=allanweiyu&a[i];
		maxx_a=max(maxx_a,a[i]);
	}
	if(n>2000){
		cout<<0;
		return 0;
	}
	if(n>20&&n<=2000){
		if(m==1){
			cout<<maxx_a;
			return 0;
		}else if(m==2){
			int ans=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					ans=max(ans,a[i]&a[j]);
			cout<<ans;
			return 0;
		}else{
			cout<<allanweiyu;
			return 0;
		}
	}
	if(m==1){
		cout<<maxx_a;
		return 0;
	}else if(m==2){
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}else if(m==3){
		int ans=0;
		for(int i=0;i<n;i++)
			for(int i_1=i+1;i_1<n;i_1++)
				for(int i_2=i_1+1;i_2<n;i_2++)
					ans=max(ans,a[i]&a[i_1]&a[i_2]);
		cout<<ans;
		return 0;
	}else if(m==4){
		int ans=0;
		for(int i=0;i<n;i++)
			for(int i_1=i+1;i_1<n;i_1++)
				for(int i_2=i_1+1;i_2<n;i_2++)
					for(int i_3=i_2+1;i_3<n;i_3++)
						ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]);
		cout<<ans;
		return 0;
	}else if(m==5){
		int ans=0;
		for(int i=0;i<n;i++)
			for(int i_1=i+1;i_1<n;i_1++)
				for(int i_2=i_1+1;i_2<n;i_2++)
					for(int i_3=i_2+1;i_3<n;i_3++)
						for(int i_4=i_3+1;i_4<n;i_4++)
							ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]&a[i_4]);
		cout<<ans;
		return 0;
	}else if(m==6){
		int ans=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]&a[i_4]&a[i_5]);
		cout<<ans;
		return 0;
	}else if(m==7){
		int ans=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++)
		ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]&a[i_4]&a[i_5]&a[i_6]);
		cout<<ans;
		return 0;
	}else if(m==8){
		int ans=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++)
		for(int i_7=i_6+1;i_7<n;i_7++)
		ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]&a[i_4]&a[i_5]&a[i_6]&a[i_7]);
		cout<<ans;
		return 0;
	}else if(m==9){
		int ans=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++)
		for(int i_7=i_6+1;i_7<n;i_7++)
		for(int i_8=i_7+1;i_8<n;i_8++)
		ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]&a[i_4]&a[i_5]&a[i_6]&a[i_7]&a[i_8]);
		cout<<ans;
		return 0;
	}else if(m==10){
		int ans=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++)
		for(int i_7=i_6+1;i_7<n;i_7++)
		for(int i_8=i_7+1;i_8<n;i_8++)
		for(int i_9=i_8+1;i_9<n;i_9++)
		ans=max(ans,a[i]&a[i_1]&a[i_2]&a[i_3]&a[i_4]&a[i_5]&a[i_6]&a[i_7]&a[i_8]&a[i_9]);
		cout<<ans;
		return 0;
	}else if(m==11){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++)
		for(int i_7=i_6+1;i_7<n;i_7++)
		for(int i_8=i_7+1;i_8<n;i_8++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2||k==i_3||k==i_4||k==i_5||k==i_6||k==i_7||k==i_8) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==12){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++)
		for(int i_7=i_6+1;i_7<n;i_7++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2||k==i_3||k==i_4||k==i_5||k==i_6||k==i_7) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==13){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++)
		for(int i_6=i_5+1;i_6<n;i_6++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2||k==i_3||k==i_4||k==i_5||k==i_6) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==14){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++)
		for(int i_5=i_4+1;i_5<n;i_5++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2||k==i_3||k==i_4||k==i_5) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==15){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++)
		for(int i_4=i_3+1;i_4<n;i_4++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2||k==i_3||k==i_4) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==16){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++)
		for(int i_3=i_2+1;i_3<n;i_3++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2||k==i_3) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==17){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++)
		for(int i_2=i_1+1;i_2<n;i_2++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1||k==i_2) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==18){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++)
		for(int i_1=i+1;i_1<n;i_1++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i||k==i_1) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==19){
		int ans=0;
		bool f=0;
		for(int i=0;i<n;i++){
			int linshi=0;
			for(int k=0;k<n;k++){
				if(k==i) continue;
				else{
					if(f==0) linshi=a[k];
					else linshi=linshi&a[k];
				}
			}
			ans=max(ans,linshi);
		}
		cout<<ans;
		return 0;
	}else if(m==20){
		cout<<allanweiyu;
		return 0;
	}
	return 0;
}
