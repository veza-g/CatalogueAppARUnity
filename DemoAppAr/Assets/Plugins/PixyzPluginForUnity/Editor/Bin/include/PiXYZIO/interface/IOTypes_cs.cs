#pragma warning disable CA2101

using System;
using System.Security;
using System.Runtime.InteropServices;

namespace Pixyz.IO.Native {

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct LocalDirectoryAccess
	{
		public LocalDirectoryAccess(LocalDirectoryAccess o) {
			this.path = o.path;
		}
		public System.String path;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct LocalDirectoryAccess_c
	{
		public IntPtr path;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct OpenStackAccess
	{
		public OpenStackAccess(OpenStackAccess o) {
			this.path = o.path;
			this.authUrl = o.authUrl;
			this.region = o.region;
			this.user = o.user;
			this.password = o.password;
			this.domainId = o.domainId;
			this.projectId = o.projectId;
			this.container = o.container;
			this.objectStore = o.objectStore;
		}
		public System.String path;
		public System.String authUrl;
		public System.String region;
		public System.String user;
		public System.String password;
		public System.String domainId;
		public System.String projectId;
		public System.String container;
		public System.String objectStore;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct OpenStackAccess_c
	{
		public IntPtr path;
		public IntPtr authUrl;
		public IntPtr region;
		public IntPtr user;
		public IntPtr password;
		public IntPtr domainId;
		public IntPtr projectId;
		public IntPtr container;
		public IntPtr objectStore;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct DropBoxAccess
	{
		public DropBoxAccess(DropBoxAccess o) {
			this.path = o.path;
			this.token = o.token;
		}
		public System.String path;
		public System.String token;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct DropBoxAccess_c
	{
		public IntPtr path;
		public IntPtr token;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct OwnCloudAccess
	{
		public OwnCloudAccess(OwnCloudAccess o) {
			this.path = o.path;
			this.authUrl = o.authUrl;
			this.user = o.user;
			this.password = o.password;
		}
		public System.String path;
		public System.String authUrl;
		public System.String user;
		public System.String password;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct OwnCloudAccess_c
	{
		public IntPtr path;
		public IntPtr authUrl;
		public IntPtr user;
		public IntPtr password;
	}

	public enum Protocol
	{
		HTTP = 1,
		HTTPS = 2,
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public class WebDAVAccess
	{
		public WebDAVAccess() {}
		public WebDAVAccess(WebDAVAccess o) {
			this.path = o.path;
			this.host = o.host;
			this.port = o.port;
			this.protocol = o.protocol;
			this.user = o.user;
			this.password = o.password;
			this.url = o.url;
		}
		public System.String path;
		public System.String host;
		public System.UInt16 port;
		public Protocol protocol;
		public System.String user;
		public System.String password;
		public System.String url;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct WebDAVAccess_c
	{
		public IntPtr path;
		public IntPtr host;
		public System.UInt16 port;
		public Int32 protocol;
		public IntPtr user;
		public IntPtr password;
		public IntPtr url;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct CloudDirectory
	{
		public enum Type
		{
			UNKNOWN = 0,
			LOCAL = 1,
			OPENSTACK = 2,
			DROPBOX = 3,
			OWNCLOUD = 4,
			WEBDAV = 5,
		}
		public LocalDirectoryAccess local;
		public OpenStackAccess openStack;
		public DropBoxAccess dropBox;
		public OwnCloudAccess ownCloud;
		public WebDAVAccess webDAV;
		public Type _type;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct CloudDirectory_c
	{
		public LocalDirectoryAccess_c local;
		public OpenStackAccess_c openStack;
		public DropBoxAccess_c dropBox;
		public OwnCloudAccess_c ownCloud;
		public WebDAVAccess_c webDAV;
		public int _type;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct LocalFileAccess
	{
		public LocalFileAccess(LocalFileAccess o) {
			this.path = o.path;
		}
		public System.String path;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct LocalFileAccess_c
	{
		public IntPtr path;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public struct CloudFile
	{
		public enum Type
		{
			UNKNOWN = 0,
			LOCAL = 1,
			OPENSTACK = 2,
			DROPBOX = 3,
			OWNCLOUD = 4,
			WEBDAV = 5,
		}
		public LocalFileAccess local;
		public OpenStackAccess openStack;
		public DropBoxAccess dropBox;
		public OwnCloudAccess ownCloud;
		public WebDAVAccess webDAV;
		public Type _type;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct CloudFile_c
	{
		public LocalFileAccess_c local;
		public OpenStackAccess_c openStack;
		public DropBoxAccess_c dropBox;
		public OwnCloudAccess_c ownCloud;
		public WebDAVAccess_c webDAV;
		public int _type;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public class ExportFilePathList {
		public System.String[] list;
		public int length { get { return (list != null) ? list.Length : 0; } }
		public ExportFilePathList() {}
		public ExportFilePathList(System.String[] tab) { list = tab; }
		public static implicit operator System.String[](ExportFilePathList o) { return o.list; }
		public System.String this[int index] {
			get { return list[index]; }
			set { list[index] = value; }
		}
		public ExportFilePathList(int size) { list = new System.String[size]; }
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct ExportFilePathList_c
	{
		public System.UInt64 size;
		public IntPtr ptr;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public class FilesList {
		public System.String[] list;
		public int length { get { return (list != null) ? list.Length : 0; } }
		public FilesList() {}
		public FilesList(System.String[] tab) { list = tab; }
		public static implicit operator System.String[](FilesList o) { return o.list; }
		public System.String this[int index] {
			get { return list[index]; }
			set { list[index] = value; }
		}
		public FilesList(int size) { list = new System.String[size]; }
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct FilesList_c
	{
		public System.UInt64 size;
		public IntPtr ptr;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public class Format
	{
		public Format() {}
		public Format(Format o) {
			this.name = o.name;
			this.extensions = o.extensions;
		}
		public System.String name;
		public Core.Native.StringList extensions;
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct Format_c
	{
		public IntPtr name;
		public Core.Native.StringList_c extensions;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public class FormatList {
		public IO.Native.Format[] list;
		public int length { get { return (list != null) ? list.Length : 0; } }
		public FormatList(IO.Native.Format[] tab) { list = tab; }
		public static implicit operator IO.Native.Format[](FormatList o) { return o.list; }
		public IO.Native.Format this[int index] {
			get { return list[index]; }
			set { list[index] = value; }
		}
		public FormatList(int size) { list = new IO.Native.Format[size]; }
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct FormatList_c
	{
		public System.UInt64 size;
		public IntPtr ptr;
	}

	[Serializable]
	[StructLayout(LayoutKind.Sequential)]
	public class ImportFilePathList {
		public System.String[] list;
		public int length { get { return (list != null) ? list.Length : 0; } }
		public ImportFilePathList() {}
		public ImportFilePathList(System.String[] tab) { list = tab; }
		public static implicit operator System.String[](ImportFilePathList o) { return o.list; }
		public System.String this[int index] {
			get { return list[index]; }
			set { list[index] = value; }
		}
		public ImportFilePathList(int size) { list = new System.String[size]; }
	}

	[StructLayout(LayoutKind.Sequential)]
	public struct ImportFilePathList_c
	{
		public System.UInt64 size;
		public IntPtr ptr;
	}

}
