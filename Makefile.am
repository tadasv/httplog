SUBDIRS = src
DIST_SUBDIRS = src
ACLOCAL_AMFLAGS = -I config
EXTRA_DIST = README.md src test autogen.sh

test: all
	cd test && $(MAKE) check && $(MAKE) test_lua

# Distribution hook gets executed when we run make dist. This target
# will create a source tarball which is later used to build a debian package.
# due to some weirdness in how we extract git hash, we are going to store
# git hash of the head in git_hash file inside of the source tarball.
# Memoryfly build depends on GIT_HASH being defined which will be
# pulled form config/git_hash.
dist-hook:
	git log -n 1 --format="%h" -- ./ > $(distdir)/config/git_hash

DEBSOURCEPKG=$(PACKAGE)_$(VERSION).orig.tar.gz
DEBSOURCEDIR=$(PACKAGE)-$(VERSION)
deb: dist
	echo "Building Debian package..."
	if test ! -d debian; then \
		echo "The files needed for building a Debian package are not"\
		"included by default in the distribution. To build a package, check"\
		"out the project from source control."; \
		exit 1; \
	fi;
	mv $(PACKAGE)-$(VERSION).tar.gz $(DEBSOURCEPKG)
	tar -xzf $(DEBSOURCEPKG)
	mkdir -p $(DEBSOURCEDIR)/debian
	cp debian/changelog debian/compat debian/control debian/copyright debian/rules $(DEBSOURCEDIR)/debian
	cd $(DEBSOURCEDIR)
	dpkg-buildpackage -rfakeroot -D -us -uc
	cd $(srcdir)
	rm -f $(DEBSOURCEPKG)
	rm -rf $(DEBSOURCEDIR)
