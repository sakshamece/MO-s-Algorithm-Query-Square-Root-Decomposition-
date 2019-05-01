#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
vector<pair<ll,ll>> v;
int block;
bool compare(pair<ll,ll> a,pair<ll,ll> b)
{
    if(a.first/block!=b.second/block)
    return a.first/block<b.first/block;
 
    return a.second<b.second;
}
void MO(ll *arr,ll n,vector<pair<ll,ll>> v)
{
    block=(ll) sqrt(n);
    sort(v.begin(),v.end(),compare);
    ll current_left=0,current_right=0;
    ll sum=0;
    int m=v.size();
    for(int i=0;i<m;i++)
    {
        ll l=v[i].first,r=v[i].second;
        while(current_left<l)
        {
            sum-=arr[current_left];
            current_left++;
        }
        while(current_left>l)
        {
            sum+=arr[current_left];
            current_left--;
        }
        while(current_right<=r)
        {
            sum+=arr[current_right];
            current_right++;
        }
        while(current_right>r+1)
        {
            sum-=arr[current_right-1];
            current_right--;
        }
        cout<<"["<<l<<":"<<r<<"]"<<" "<<sum<<endl;
 
    }
}
int main() {
    ll arr[] = {1, 1, 2, 1, 3, 4, 5, 2, 8}; 
    ll n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<ll,ll>> v ={{0, 4}, {1, 3}, {2, 4}}; 
    MO(arr,n,v);
}
