#include"iostream"
#include<string>
using namespace std;
int n;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=0;i<a;i++)
            s.push_back(c);
    }
    //cout<<s<<" "<<s.size()<<endl;
    int s_sz=s.size();
    //if(s_sz%2==1){
        string q="",h="";
        long long int ans=0;
        for(int i=0;i<s_sz/2;i++)
            q.push_back(s[i]);
        for(int i=s_sz/2+1;i<s_sz;i++)
            h.push_back(s[i]);
        for(int i=0;i<s_sz/2;i++)
            if(q[i]!=h[i])
                ans++;
        cout<<ans<<endl;
    //}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// AK CSP!
